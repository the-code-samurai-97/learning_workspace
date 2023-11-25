# Use the official Ubuntu 20.04 LTS base image
FROM ubuntu:22.04


# Set environment variables to avoid interactive prompts during installation
ENV DEBIAN_FRONTEND=interactive

# Update the package list and install necessary packages
RUN apt-get update && \
    apt-get install -y \
        apt-transport-https \
        curl \
        gnupg \
        wget \
        bash \
        bash-completion \
        pkgconf \
        unzip \
        wget \
        zip
RUN apt-get install libglew-dev \
            libc6-dev \
            libx11-dev \
            libpthread-stubs0-dev
##if
#https://github.com/bazelbuild/bazel/releases/download/7.0.0/bazel-7.0.0-installer-linux-x86_64.sh \

RUN wget https://github.com/bazelbuild/bazel/releases/download/6.4.0/bazel-6.4.0-installer-linux-x86_64.sh
RUN chmod u+x bazel-6.4.0-installer-linux-x86_64.sh
RUN bash bazel-6.4.0-installer-linux-x86_64.sh
RUN rm bazel-6.4.0-installer-linux-x86_64.sh

RUN echo 'export PATH="/usr/local/bin:${PATH}"' >> ~/.bashrc
# Add line to ~/.bashrc for Bazel completion
RUN echo 'source /usr/local/lib/bazel/bin/bazel-complete.bash' >> ~/.bashrc

RUN rm -rf /var/lib/apt/lists/*

# Create a non-root user
RUN groupadd -r nonrootgroup && useradd --no-log-init -r -g nonrootgroup nonrootuser

# Set a non-root user and switch to that user
USER nonrootuser

# Set the working directory to /workspace
WORKDIR /home/nonrootuser/workspace
RUN chown -R nonrootuser /home/nonrootuser/workspace
CMD ["/bin/bash"]
CMD source /root/.bashrc
CMD cd /home/nonrootuser/workspace
# Print Bazel version information
CMD ["bazel", "--version"]
