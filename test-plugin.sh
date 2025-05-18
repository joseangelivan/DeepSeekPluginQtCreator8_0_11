#!/bin/bash
# Test script to verify the DeepSeek plugin loads properly

# Variables que debes ajustar según tu entorno
QTC_DIR=/opt/qtcreator-16.0.1
QTC_BIN=$QTC_DIR/bin/qtcreator
QT_DIR=/opt/Qt/6.8.0/gcc_64/

# Create plugin directory if it doesn't exist
mkdir -p $QTC_DIR/lib/qtcreator/plugins

# Copy the plugin to the Qt Creator plugins directory
cp build/libDeepSeekPlugin.so $QTC_DIR/lib/qtcreator/plugins/

# Set environment variables
export LD_LIBRARY_PATH=$QT_DIR/lib:$QTC_DIR/lib/qtcreator:$LD_LIBRARY_PATH
export QT_PLUGIN_PATH=$QTC_DIR/lib/qtcreator/plugins:$QT_PLUGIN_PATH

# Run Qt Creator with verbose plugin loading
$QTC_BIN -log-time -v

echo "Test completed. Check the output above for plugin loading information."
echo "You should see 'DeepSeekPlugin' in the loaded plugins list."
