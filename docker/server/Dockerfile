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


RUN mkdir /opt/csOroneta
WORKDIR /opt/csOroneta

# Copy all files from the builder stage
COPY --from=builder /opt/oronetaBuilder/bin .

# Copy static files
COPY ./static/ .


# tail ./test.log
CMD ["./script/showTree.sh"]
