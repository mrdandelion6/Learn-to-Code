# learn docker
welcome to my docker notes. 

docker is a platform to develop, ship, and run applications in "containers." 

## what is a container?
a container is a unit of software that packages up code and all its dependencies so the application runs quickly and reliably from one computing environment to another.

so things across different machines are consistent with containers!

### what a container includes
- **base image**: foundation of the container that provides the initial filesystem. it is a minimal operating system environment. some common base images are ubuntu , debian , and alpine.
- **dependencies**: libraries , packages , and software for the base layer--installed via package managers like apt , pacman , yum , or pip.
- **application code**: the actual files for the application: scripts and executables.
- **configuration files**: the files that define application settings , connection settings , and run time behaviours. may be stored in places like `/etc` or `/config` in the container.
- **environment variables**: key-value pairs accessible by applications at run time. defined in the `Dockerfile` ... see below
- **Dockerfile**: not part of the container itself , but the blueprint that defines how to build the base image , installation steps , and runtime configuration such as environment variables. more detail on this later on.
- **container filesystem**: a layered filesystem that gets created when building the container. contains all the dependencies. more on this later.
- **volume mounts**: connections to persistent storage outside the container

#### base image
to better understand how docker works , we will explore what the base image exactly is. it is essentially a stripped down OS.

the base image consists of:
- minimal OS environment such as core utilities , basic shell , essential system libraries
- filesystem. base image has a root filesystem with the standard linux directory structure (/bin , /etc , /lib).

unlike a traditional OS , docker images dont have the following:
- no kernel. they share the host machine's kernel which is a key difference from something like a virtual machine.
- no an EFI system partition (ESP). containers don't boot like traditional systems.. so no ESP is needed for storing and configuring bootloaders.
- no swap partition. memory is usually managed by the by the host system.
- no device drivers. since containers share the host kernel , they share device drivers.

## how does docker work?
docker uses a client-server architecture. the docker client talks to the docker daemon, which does the heavy lifting of building, running, and distributing your docker containers.

### containers
think of each container like a little ecosystem that's running where you can specify what dependencies are needed and of course the ecosystem itself: ubuntu , debian , alpine.

### dockerfile
to use docker, you need to create a `Dockerfile`. this file contains instructions on how to build the image.

### images
a docker image is just like a system image , it is snapshot or blueprint of the container to run. think of a container as a running operating system , and a docker image as a snapshot of that system before it runs... like an image of an operating system.

you specify all the details of the ecosystem in this file. the file is literally named "Dockerfile" , like how you might have a `Makefile` in C.

### dockerfile -> docker image -> docker container
here is an overview of the process for creating containers:
- a dockerfile is written by developer
- a docker image is built from a dockerfile: `docker build -t <image_name>` or `docker-compose build`
- a docker container is started and run from an existing image: `docker run <image_name>`

however , there is another step that may often may happen before the dockerfile builds an image.. this is there is an additional docker-compose.yml file (see below).

### docker-compose.yml
in addition to a dockerfile we also have a `docker-compose.yml`. this is a configuration file used by docker for when we:
- need to configure multiple related services in one file
- define networks between containers
- set up volumes for persistent data
- manage environment variables across containers
- need multiple containers for the application
- want to simplify complex Dockerfile run commands

note that each "service" has its own dockerfile on instructions for how to create a container. **each service is its own independent blueprint for making a container**. 

containers built from the services can communicate and work together , much like microservices architecture if you know a bit about that.

remember that services are each defined by their own dockerfile... a service is not a container , it is like a dockerfile... just a configuration to make an image which a container loads.

## full pipeline for docker
including the docker-compose.yml file , this is the entire process for docker:
- the `docker-compose build` command is run and docker reads the `docker-compose.yml` file in the current directory.
- for each service defined in the `docker-compose.yml` file , docker looks for its dockerfile.
- docker reads the services' dockerfiles and builds any images.
- docker runs the containers from images , all good to go

