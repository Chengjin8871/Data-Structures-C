@echo off
REM ============================================================
REM  Data-Structures-C / daily auto-sync script
REM
REM  Usage:
REM    sync.bat          -> interactive (pauses at the end)
REM    sync.bat /auto    -> silent (used by Windows Task Scheduler)
REM
REM  Log file: .git\sync-log.txt  (not tracked by git)
REM ============================================================
chcp 65001 >nul 2>&1
setlocal

cd /d "%~dp0"

set "LOGFILE=%~dp0.git\sync-log.txt"
if not exist "%~dp0.git\" mkdir "%~dp0.git" 2>nul

echo ============================================================>> "%LOGFILE%"
echo [%date% %time%] === sync start ===>> "%LOGFILE%"

REM ---------- build an ASCII timestamp for the commit message ----------
for /f "tokens=1-3 delims=/-. " %%a in ("%date%") do set "DY=%%a-%%b-%%c"
set "TM=%time: =0%"
set "TM=%TM:~0,8%"
set "STAMP=%DY% %TM%"

echo [1/4] git add -A ...
git add -A>> "%LOGFILE%" 2>&1
if errorlevel 1 goto :fail

git diff --cached --quiet
if not errorlevel 1 (
    echo No changes to commit. Nothing to do.
    echo [%STAMP%] no changes - skipped>> "%LOGFILE%"
    goto :done
)

echo [2/4] git commit ...
git commit -m "auto-sync %STAMP%">> "%LOGFILE%" 2>&1
if errorlevel 1 goto :fail

echo [3/4] git pull --rebase ...
git pull --rebase origin main>> "%LOGFILE%" 2>&1
if errorlevel 1 (
    echo Rebase failed - aborting.
    git rebase --abort>> "%LOGFILE%" 2>&1
    goto :fail
)

echo [4/4] git push ...
git push origin main>> "%LOGFILE%" 2>&1
if errorlevel 1 goto :fail

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
