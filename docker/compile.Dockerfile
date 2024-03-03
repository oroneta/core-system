FROM registry.access.redhat.com/ubi9/ubi:9.3

LABEL version="0.1"
LABEL description="Core System for Oroneta Project"

RUN apt update
RUN apt install -y vim gcc make
RUN mkdir /opt/Ciso8583

# Set root path
WORKDIR /opt/Ciso8583

# Copy project
COPY src src
COPY docker/buildContainer.sh .

# Create environment
RUN mkdir bin build dist tmp
RUN chmod +x ./buildContainer.sh

# CMD ["ls", "-l"]
CMD ./buildContainer.sh