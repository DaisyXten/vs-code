# Docker proxy configuration

## System-wide

1. Create file `/etc/systemd/system/docker.service.d/http-proxy.conf` and paste into it:
   ```
   [Service]
   Environment="HTTP_PROXY=http://proxy-chain.intel.com:911" "NO_PROXY=intel.com,.intel.com,localhost,127.0.0.1"
   ```
2. Create file `/etc/systemd/system/docker.service.d/https-proxy.conf` and paste int it:
   ```
   [Service]
   Environment="HTTPS_PROXY=http://proxy-chain.intel.com:912" "NO_PROXY=intel.com,.intel.com,localhost,127.0.0.1"
   ```
3. Update `/etc/resolv.conf` file:
   1. Install `resolvconf` package: `sudo apt install resolvconf`
   2. Add following lines to file `/etc/resolvconf/resolv.conf.d/tail`
   ```
   search igk.intel.com
   nameserver 10.248.2.1
   nameserver 10.216.46.196
   nameserver 163.33.253.68
   ```
   3. Update `/etc/resolv.conf` file with command: `sudo resolvconf -u`
   This ensure that above additional lines will be always added to `/etc/resolv.conf` file.
4. Refresh system:
   ```
   sudo systemctl daemon-reload
   sudo systemctl restart docker
   ```

## Inside Docker

1. At the beginning of your `Dockerfile` add:
   ```
   ENV LAST_UPDATED 2018-05-28:15:40
   ENV LC_CTYPE=C.UTF-8

   # Define proxies
   ENV http_proxy=http://proxy-chain.intel.com:911
   ENV https_proxy=http://proxy-chain.intel.com:911
   ENV ftp_proxy=http://proxy-chain.intel.com:911
   ```

## Post install

1. Add user to `docker` group
```
    sudo usermod -a -G docker $USER
```
2. Logout and login back in order to changes take effect.
