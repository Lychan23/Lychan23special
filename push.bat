@echo off
git add .
git commit -m "update"
git status
timeout /t 5 >nul
git push -f origin main
