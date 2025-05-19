#!/bin/bash
# Enhanced Qt Creator Plugin Compilation Script
# Use this script to compile and install the DeepSeek plugin for Qt Creator 16.0.1

# Exit on error
set -e

# Variables that should be adjusted for your environment
QTC_DIR=/opt/qtcreator-16.0.1
QT_DIR=/opt/Qt/6.8.0/gcc_64

# Show configuration
echo "=== DeepSeek Plugin Build Configuration ==="
echo "Qt Creator dir: $QTC_DIR"
echo "Qt dir: $QT_DIR"
echo "========================================"

# Prepare environment
export PATH=$QT_DIR/bin:$PATH
export LD_LIBRARY_PATH=$QT_DIR/lib:$LD_LIBRARY_PATH
export QTC_SOURCE=$QTC_DIR
export QTC_BUILD=$QTC_DIR

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Clean previous build
echo "Cleaning previous build..."
rm -rf *

# Configure and compile
echo "Running qmake..."
$QT_DIR/bin/qmake ../DeepSeekPlugin.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
echo "Building plugin..."
make -j$(nproc)

# Check if build was successful
if [ ! -f libDeepSeekPlugin.so ]; then
    echo "Error: Build failed! libDeepSeekPlugin.so not found."
    exit 1
fi

# Install plugin
echo "Installing plugin..."
mkdir -p $QTC_DIR/lib/qtcreator/plugins
cp libDeepSeekPlugin.so $QTC_DIR/lib/qtcreator/plugins/

echo "Creating symbolic links (for compatibility)..."
cd $QTC_DIR/lib/qtcreator/plugins
ln -sf libDeepSeekPlugin.so libDeepSeekPlugin.so.1
ln -sf libDeepSeekPlugin.so.1 libDeepSeekPlugin.so.1.0
ln -sf libDeepSeekPlugin.so.1.0 libDeepSeekPlugin.so.1.0.0
cd -

echo "=== Build Summary ==="
echo "Plugin compiled and installed successfully!"
echo "To test the plugin, run: $QTC_DIR/bin/qtcreator"
echo "If the plugin doesn't load, try with: $QTC_DIR/bin/qtcreator -noload Welcome -log-time -vvv"
echo "===================="
