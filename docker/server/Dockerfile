# Build stage
FROM registry.access.redhat.com/ubi9/ubi:9.3 as builder

WORKDIR /opt/oronetaBuilder


#Install dependecies 
RUN yum update -y
RUN yum install -y  \
        wget        \ 
        tar         \
        vim         \
        g++         \
        make        \
        cmake       



# jsoncpp dependencies
RUN yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-9.noarch.rpm
RUN yum -y install jsoncpp-devel
# end jsoncpp

# boost dependencies
RUN yum -y install https://pkgs.sysadmins.ws/el9/base/x86_64/boost1.81-devel-1.81.0-7.el9.x86_64.rpm --skip-broken
# RUN yum -y install boost1.81-devel
# end boost


# Generate all
RUN ./script/generateAll.sh


WORKDIR /opt/oronetaBuilder/build
# RUN cmake .. && make

# Make y copiar los binarios a /opt/oronetaBuilder/bin
RUN mkdir -p /opt/oronetaBuilder/bin



# ---------------------------------------------
# Production stage
FROM registry.access.redhat.com/ubi9/ubi:9.3


RUN mkdir /opt/csOroneta
WORKDIR /opt/csOroneta

# Copy all files from the builder stage
COPY --from=builder /opt/oronetaBuilder/bin .

# Copy static files
COPY ./static/ .


# tail ./test.log
CMD ["./script/showTree.sh"]
