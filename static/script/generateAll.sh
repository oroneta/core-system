# Generate 
#   - var
#      - log
#      - tmp

mkdir -p var/log
mkdir -p var/tmp
 

sudo apt-get install wget
# chmod +x script/generateAll.sh

#Install dependences Crow
# Descargar Crow
wget https://github.com/CrowCpp/Crow/archive/refs/tags/v1.1.0.tar.gz

# Crear directorio para Crow
mkdir crow

# Extraer archivos de Crow
tar xvfz v1.1.0.tar.gz -C crow --strip-components=1

# Eliminar archivo descargado
rm v1.1.0.tar.gz

# Instalar dependencias de Crow
sudo apt-get update
sudo apt-get install -y libboost-all-dev
