# DeepSeek Plugin for Qt Creator

This plugin integrates DeepSeek AI capabilities into Qt Creator 8.0.1 (based on Qt 5.14.2 gcc_64).

## Features

- Send code selections directly to DeepSeek AI
- Configure API settings
- View responses in the output pane

## Installation

### Build from Source

1. Make sure you have Qt Creator 8.0.1 installed
2. Clone this repository
3. Configure the paths in `DeepSeekPlugin.pro` to point to your Qt Creator installation
4. Build the plugin using qmake:
   ```
   cd DeepSeekPlugin
   qmake
   make
   ```
5. Copy the built plugin to Qt Creator's plugin directory:
   ```
   cp libDeepSeekPlugin.so ~/path/to/qtcreator/lib/qtcreator/plugins/
   ```

### Configure the Plugin

1. Open Qt Creator
2. Go to Tools > Options > DeepSeek
3. Enter your DeepSeek API key
4. Configure other settings as needed

## Usage

1. Select code in the editor
2. Right-click and select "Ask DeepSeek" or use the Tools > DeepSeek > Ask DeepSeek menu option
3. Enter your prompt
4. View the response in the DeepSeek output pane

## Requirements

- Qt Creator 8.0.1
- Qt 5.14.2
- DeepSeek API key

## License

This project is licensed under the MIT License - see the LICENSE file for details.
