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

think of each container like a little ecosystem where you can specify what dependencies are needed and of course the ecosystem itself: ubuntu , debian , alpine.

you specify all the details of the ecosystem using a `Dockerfile`--a file that's literally named "Dockerfile" , like how you might have a `Makefile` in C.

## dockerfile
to use docker, you need to create a dockerfile. this file contains instructions on how to build the image.

## docker-compose.yml
a `docker-compose.yml` file is a configuration file used by docker for when we:
- need to configure multiple related services in one file
- define networks between containers
- set up volumes for persistent data
- manage environment variables across containers
- need multiple containers for the application
- want to simplify complex Dockerfile run commands
