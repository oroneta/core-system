# Build stage
FROM registry.access.redhat.com/ubi9/ubi:9.3 as builder

WORKDIR /opt/oronetaBuilder


#Install dependecies 
RUN yum update -y && \
    yum install -y wget tar && \
    yum install -y boost boost-devel jsoncpp jsoncpp-devel && \
    yum install -y vim gcc make


# Generate all
RUN ./script/generateAll.sh


WORKDIR /opt/oronetaBuilder/build
RUN cmake .. && make

# Make y copiar los binarios a /opt/oronetaBuilder/bin
RUN mkdir -p /opt/oronetaBuilder/bin



# ---------------------------------------------
# Production stage
FROM registry.access.redhat.com/ubi9/ubi:9.3

# Install postgresql library libpqxx
RUN yum install --nogpgcheck -y https://download.postgresql.org/pub/repos/yum/reporpms/EL-9-x86_64/pgdg-redhat-repo-latest.noarch.rpm && \
    yum install --nogpgcheck -y postgresql14-14.7 postgresql14-devel-14.7 postgresql14-libs-14.7


RUN mkdir /opt/csOroneta
WORKDIR /opt/csOroneta

# Copy all files from the builder stage
COPY --from=builder /opt/oronetaBuilder/bin .

# Copy static files
COPY ./static/ .


# tail ./test.log
CMD ["tail", "-f", "/dev/null"]
