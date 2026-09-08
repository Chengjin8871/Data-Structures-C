@echo off
REM ============================================================
REM  Data-Structures-C / daily auto-sync script
REM
REM  IMPORTANT: THIS FILE MUST STAY PURE ASCII.
REM  cmd.exe reads .bat files using the system ANSI codepage
REM  (936/GBK on this machine). Any UTF-8 Chinese character in a
REM  REM line used to corrupt the parse and break every command
REM  below it -> "not a git repository" on 2026-09-08 21:00.
REM  Keep comments and messages in English only.
REM
REM  Usage:
REM    sync.bat          -> interactive (pauses at the end)
REM    sync.bat /auto    -> silent (used by Windows Task Scheduler)
REM
REM  Log file: .git\sync-log.txt  (not tracked by git)
REM ============================================================
setlocal

REM ---- repo dir: use %~dp0. so the trailing backslash is harmless ----
set "REPO=%~dp0."
set "LOGFILE=%~dp0.git\sync-log.txt"
if not exist "%~dp0.git\" mkdir "%~dp0.git" 2>nul

REM ---- ssh must go through port 443 (port 22 is refused here) ----
REM ---- do not rely on ~/.ssh/config being read in scheduler context ----
if not defined HOME set "HOME=%USERPROFILE%"
set "GIT_TERMINAL_PROMPT=0"
if not defined GIT_SSH_COMMAND set "GIT_SSH_COMMAND=ssh -p 443 -o StrictHostKeyChecking=accept-new"

echo ============================================================>> "%LOGFILE%"
echo [%date% %time%] === sync start ===>> "%LOGFILE%"
echo [%date% %time%] repo=%REPO%>> "%LOGFILE%"

REM ---------- build an ASCII timestamp for the commit message ----------
set "STAMP="
for /f "usebackq delims=" %%i in (`powershell -NoProfile -NonInteractive -Command "Get-Date -Format yyyy-MM-dd_HH-mm-ss" 2^>nul`) do set "STAMP=%%i"
if not defined STAMP set "STAMP=%date% %time%"

echo [1/4] git add -A ...
git -C "%REPO%" add -A>> "%LOGFILE%" 2>&1
if errorlevel 1 goto :fail

git -C "%REPO%" diff --cached --quiet
if not errorlevel 1 (
    echo No changes to commit. Nothing to do.
    echo [%STAMP%] no changes - skipped>> "%LOGFILE%"
    goto :done
)

echo [2/4] git commit ...
git -C "%REPO%" commit -m "auto-sync %STAMP%">> "%LOGFILE%" 2>&1
if errorlevel 1 goto :fail

echo [3/4] git pull --rebase ...
git -C "%REPO%" pull --rebase origin main>> "%LOGFILE%" 2>&1
if errorlevel 1 (
    echo Rebase failed - aborting.
    git -C "%REPO%" rebase --abort>> "%LOGFILE%" 2>&1
    goto :fail
)

echo [4/4] git push ...
git -C "%REPO%" push origin main>> "%LOGFILE%" 2>&1
if not errorlevel 1 goto :ok

REM ---------- network hiccup? wait 10s and retry once ----------
echo Push failed, retrying in 10s ...
echo [%STAMP%] first push failed, retrying>> "%LOGFILE%"
ping -n 11 127.0.0.1 >nul 2>&1
git -C "%REPO%" push origin main>> "%LOGFILE%" 2>&1
if errorlevel 1 goto :fail

:ok
echo.
echo [OK] Pushed to GitHub successfully.  %STAMP%
echo [%STAMP%] SUCCESS>> "%LOGFILE%"
goto :done

:fail
echo.
echo [ERROR] Sync failed. See log: %LOGFILE%
echo [%STAMP%] FAILED>> "%LOGFILE%"

:done
if /i "%~1"=="/auto" goto :eof
echo.
pause
