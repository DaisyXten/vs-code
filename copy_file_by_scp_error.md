# Error
error: kex protocol error: type 30 seq 1 [preauth] 正确处理姿势
[reference link](https://blog.csdn.net/luozhonghua2014/article/details/80960187)

在sshd-config文件添加
```
KexAlgorithms curve25519-sha256@libssh.org,ecdh-sha2-nistp256,ecdh-sha2-nistp384,ecdh-sha2-nistp521,diffie-hellman-group14-sha1

```

