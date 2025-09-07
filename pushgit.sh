#!/bin/bash

# === KONFIGURASI ===
FOLDER="/storage/emulated/0/mlbb"  # Folder project
REPO="https://github.com/Afinnn954/ProjectHookClass.git"
USERNAME="Afinnn954"
EMAIL="mohamadarifin@gmail.com"

# === MASUK KE FOLDER ===
cd "$FOLDER" || { echo "Folder $FOLDER tidak ditemukan!"; exit 1; }

# === FIX DUBIOUS OWNERSHIP ===
git config --global --add safe.directory "$FOLDER"

# === SET IDENTITAS ===
git config --global user.name "$USERNAME"
git config --global user.email "$EMAIL"

# === INISIALISASI GIT (jika belum ada .git) ===
if [ ! -d ".git" ]; then
  git init
  git branch -M main
  git remote add origin "$REPO"
else
  git branch -M main
  git remote remove origin 2>/dev/null
  git remote add origin "$REPO"
fi

# === ADD & COMMIT ===
git add .
git commit -m "Auto commit: $(date '+%Y-%m-%d %H:%M:%S')"

# === PUSH KE GITHUB ===
git push -u origin main