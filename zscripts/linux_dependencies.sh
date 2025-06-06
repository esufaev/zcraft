#!/bin/bash
set -e

sudo apt update
sudo apt install -y \
    build-essential \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxxf86vm-dev \
    libxcursor-dev \
    libwayland-dev \
    wayland-protocols \ 
    libxinerama-dev \
    libxext-dev

