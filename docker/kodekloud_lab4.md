1. 
We just downloaded the code of an application. What is the base image used in the Dockerfile?
Inspect the Dockerfile in the webapp-color directory.
The given Dockerfile is:
```
FROM python:3.6
RUN pip install flask
COPY . /opt/
EXPOSE 8080
WORKDIR /opt
ENTRYPOINT ["python", "app.py"]
```

```
Open the Dockerfile and see the FROM. It is the base image
```

```
docker inspect --format='{{.Config.Image}}' $INSTANCE_ID
```

When a container is created using the image built with this Dockerfile, what is the command used to RUN the application inside it.


Inspect the Dockerfile in the webapp-color directory.

```
Open the Dockerfile and look for ENTRYPOINT command.
python app.py
```

What port is the web application run within the container?


Inspect the Dockerfile in the webapp-color directory

```
Open the Dockerfile and look for the port in EXPOSE command
```

Build a docker image using the Dockerfile and name it webapp-color. No tag to be specified.

```
docker build -t webapp-color .
```

Run an instance of the image webapp-color and publish port 8080 on the container to 8282 on the host.

```
docker run -p 8282:8080 webapp-color
```

What is the base Operating System used by the python:3.6 image?


If required, run an instance of the image to figure it out.

```
docker run python:3.6 cat /etc/*release*
```

What is the approximate size of the webapp-color image?

```
docker images
```

Build a new smaller docker image by modifying the same Dockerfile and name it webapp-color and tag it lite.


Hint: Find a smaller base image for python:3.6. Make sure the final image is less than 150MB.

```
Modify Dockerfile to use python:3.6-alpine image, and then build using docker build -t webapp-color:lite .
```

Run an instance of the new image webapp-color:lite and publish port 8080 on the container to 8383 on the host.

```
docker run -p 8383:8080 webapp-color:lite
```


