# Qt Creator Plugin Compilation Utils
# Este archivo lo puedes usar para compilar el plugin

# Variables que debes ajustar según tu entorno
QTC_DIR=/opt/qtcreator-16.0.1
QT_DIR=/opt/Qt/6.8.0/gcc_64/

# Prepara el entorno (ajusta las rutas según tu instalación)
export PATH=$QT_DIR/bin:$PATH
export LD_LIBRARY_PATH=$QT_DIR/lib:$LD_LIBRARY_PATH

# Compila el plugin
mkdir -p build
cd build
qmake-qt5 ../DeepSeekPlugin.pro -spec linux-g++ CONFIG+=debug
make -j4

# Instala el plugin
mkdir -p $QTC_DIR/lib/qtcreator/plugins
cp libDeepSeekPlugin.so $QTC_DIR/lib/qtcreator/plugins/

echo "Plugin compilado e instalado."
