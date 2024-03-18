# Generate 
#   - var
#      - log
#      - tmp

mkdir -p var/log
mkdir -p var/tmp
 
#Install dependences Crow
# Download Crow
wget https://github.com/CrowCpp/Crow/archive/refs/tags/v1.1.0.tar.gz

# Create directory for Crow
mkdir -p crow


tar xvfz v1.1.0.tar.gz -C crow --strip-components=1

rm v1.1.0.tar.gz



