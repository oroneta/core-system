# Build stage
FROM registry.access.redhat.com/ubi9/ubi:9.3 as builder

#Install dependecies 
RUN yum update -y
RUN yum install -y https://dl.fedoraproject.org/pub/epel/epel-release-latest-9.noarch.rpm
RUN yum install -y  \
        wget        \ 
        tar         \
        vim         \
        gcc-c++     \
        make        \
        cmake       \
        openssl-devel

# jsoncpp dependencies
RUN yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-9.noarch.rpm
RUN yum -y install jsoncpp-devel
# end jsoncpp

# Install postgresql library libpqxx
RUN yum install --nogpgcheck -y https://download.postgresql.org/pub/repos/yum/reporpms/EL-9-x86_64/pgdg-redhat-repo-latest.noarch.rpm && \
# to use -lpq
    # yum install --nogpgcheck --skip-broken -y libpq-devel postgresql-devel
    yum install --nogpgcheck --skip-broken -y postgresql14-14.7 postgresql14-devel-14.7 postgresql14-libs-14.7
    #  libpqxx-devel postgresql-devel

# asio
RUN yum -y install --nogpgcheck asio-devel

# end asio

# boost dependencies
# RUN yum -y install https://pkgs.sysadmins.ws/el9/base/x86_64/boost1.81-devel-1.81.0-7.el9.x86_64.rpm --skip-broken
# RUN yum -y install boost1.81-devel
# end boost

WORKDIR /opt/oronetaBuilder/

# Download Crow
RUN wget https://github.com/CrowCpp/Crow/archive/refs/tags/v1.1.0.tar.gz -O Crow.tar.gz
# Create directory for Crow
RUN mkdir -p crow
RUN mkdir -p crow/build
# Extract Crow
RUN tar xvfz Crow.tar.gz -C crow --strip-components=1

WORKDIR /opt/oronetaBuilder/crow/build
RUN cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF
RUN make install

# # Descargar y copiar nlohmann/json
# RUN wget https://github.com/nlohmann/json/releases/download/v3.10.2/json.hpp -O /usr/local/include/json.hpp

# MAKE PROJECT
WORKDIR /opt/oronetaBuilder/src

# Copy source code
COPY src .
# Build
RUN make clean
RUN make



#Ejecutar el program

# ---------------------------------------------
# Production stage
FROM registry.access.redhat.com/ubi9/ubi:9.3

RUN yum install --nogpgcheck -y https://download.postgresql.org/pub/repos/yum/reporpms/EL-9-x86_64/pgdg-redhat-repo-latest.noarch.rpm && \
    yum install --nogpgcheck -y postgresql14-14.7 postgresql14-devel-14.7 postgresql14-libs-14.7

RUN mkdir /opt/csOroneta
WORKDIR /opt/csOroneta

# COPY all files from the builder stage
COPY --from=builder /opt/oronetaBuilder/dist ./bin

# COPY static files
COPY ./static/ .


# tail ./test.log
CMD ["./bin/OronetaCoreServer"]
