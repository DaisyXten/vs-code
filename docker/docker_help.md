# Helpful commands

## Remove all stopped Docker containers:
```
sudo docker rm $(sudo docker ps -a -q)
```

## Remove all untagged images:
```
sudo docker rmi $(sudo docker images -q --filter "dangling=true")
```

## Run gdb under docker:
In order to enable gdb under docker run it with following arguments:
```
docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined
```

## Have access to `numactl`
Run with `--privileged` flag.

## Run image with access to nvidia GPUs
Add option: `--runtime=nvidia` to `docker run` command.

## Exit started container without stopping it
Use sequence: `CTRL+p`,`CTRL+q`

## Connect to currently running container
`docker exec -it <container_name> <command>`
To run terminal use: `docker exec -it <container_name> /bin/bash`

## Restart exited container:
`docker start -a -i <container_id>`

## Id of last created container:
``docker ps -q -l``

## Adding new volume to existing container:
```
$ docker ps  -a
CONTAINER ID        IMAGE                 COMMAND                  CREATED              STATUS                          PORTS               NAMES
    5a8f89adeead        ubuntu:14.04          "/bin/bash"              About a minute ago   Exited (0) About a minute ago                       agitated_newton

# commit dynamically change the image name of some image ID
$ docker commit 5a8f89adeead newimagename

$ docker run -ti -v "$PWD/dir1":/dir1 -v "$PWD/dir2":/dir2 newimagename /bin/bash
```

## Some other useful commands
```
docker run hello-world

```
