# Build stage
FROM registry.access.redhat.com/ubi9/ubi:9.3 as builder

WORKDIR /opt/oronetaBuilder


# Esto de aqui abajo es de ejemplo -------
RUN mkdir ./bin
RUN echo "Holaaaa" > ./bin/test.log
# Copias lo que necesites
# Y haces compile
# RUN make
#
# Recuerda hacer el make que los binarios se copien a una carpeta /opt/oronetaBuilder/bin

# ---------------------------------------------
# Production stage
FROM registry.access.redhat.com/ubi9/ubi:9.3

RUN mkdir /opt/csOroneta
WORKDIR /opt/csOroneta

# Copy all files from the builder stage
COPY --from=builder /opt/oronetaBuilder/bin .

# Copy static files
COPY ./static/ .

# Generate all
RUN ./script/generateAll.sh



# tail ./test.log
CMD ["./script/showTree.sh"]
