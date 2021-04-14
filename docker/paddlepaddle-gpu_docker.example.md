# A procedure to get paddlepaddle-gpu docker up and running on nvidia CUDA 10.2

 From https://docs.docker.com/engine/install/ubuntu/ 
 
 Install using the repository
 
 Before you install Docker Engine for the first time on a new host machine, you need to set up the Docker repository. 
  Afterwards, you can install and update Docker from the repository.

 ```console
sudo apt-get update
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common
```

 **Add Docker’s official GPG key:**

 ```console
  curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
  sudo apt-key fingerprint 0EBFCD88
  sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
```

 **INSTALL DOCKER ENGINE**
 
 ```console
   sudo apt-get update
   sudo apt-get install docker-ce docker-ce-cli containerd.io
   sudo apt-get --help
   sudo apt-get autoremove
   curl https://get.docker.com | sh   && sudo systemctl --now enable docker
   sudo usermod -aG docker andrea
```

**Verify that Docker Engine is installed correctly by running the hello-world image.**

 ```console
   docker run hello-world
```

**configuring proxy, check what it is needed in your case!**
 Also take a look at [this](https://github.com/otcshare/iags-pl-wiki/blob/master/tutorials/docker/docker_proxy_conf.md) configuration instructions.

 ```console
   sudo touch /etc/systemd/system/docker.service.d/http-proxy.conf
   sudo vi /etc/systemd/system/docker.service.d/http-proxy.conf
   ll /etc/systemd/system/
   sudo mkdir -p  /etc/systemd/system/docker.service.d/
   sudo vi /etc/systemd/system/docker.service.d/http-proxy.conf
   sudo vi /etc/systemd/system/docker.service.d/https-proxy.conf
   sudo vi /etc/resolv.conf
   ll /etc/resolvconf/
   resolvconf
   sudo apt install resolvconf
   ll /etc/resolvconf/
   sudo vi /etc/resolvconf/resolv.conf.d/tail
   sudo resolvconf -u
   sudo systemctl daemon-reload
   sudo systemctl restart docker
   docker run hello-world
   docker run --help
```

**installing nvidia docker support**

 ```console
   distribution=$(. /etc/os-release;echo $ID$VERSION_ID)    && curl -s -L https://nvidia.github.io/nvidia-docker/gpgkey | sudo apt-key add -    && curl -s -L https://nvidia.github.io/nvidia-docker/$distribution/nvidia-docker.list | sudo tee /etc/apt/sources.list.d/nvidia-docker.list
   sudo apt-get update
   sudo apt-get install -y nvidia-docker2
   sudo systemctl restart docker
```

**if necessary, delete unnecessary docker images**

 ```console
   sudo docker run --rm --gpus all nvidia/cuda:11.0-base nvidia-smi
   docker run hello-world
   sudo docker run --rm --gpus all nvidia/cuda:11.0-base nvidia-smi
   sudo docker run --rm --gpus all nvidia/cuda:10.2-base nvidia-smi
```

 **... make space disk space, this takes 25 Gigabytes!!**
 
 ```console
   docker pull paddlepaddle/paddle:2.0.0-gpu-cuda10.2-cudnn7
```

**run paddle-gpu docker**

 ```console
   docker run --runtime=nvidia -it --privileged --name=paddlepaddle-gpu -v /home/andrea/PaddleKurtosisStudy/kurtosis_4_paddle_ernie:/root/paddle paddlepaddle/paddle:2.0.0-gpu-cuda10.2-cudnn7 /bin/bash
   docker ps -a
 ```
 
 Note that you won't be able to run multiple instances of docker containers using the same GPU card. In such situation you will get an error like `CUBLAS_STATUS_NOT_INITIALIZED` or ie.: `CUDNN_STATUS_NOT_INITIALIZED`.

** Usage

You can find some helpful instructions to clean, inspect etc docker images/containers [here](https://github.com/otcshare/iags-pl-wiki/blob/master/tutorials/docker/docker_help.md).
