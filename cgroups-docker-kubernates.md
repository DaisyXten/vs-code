## How to install nvidia-docker

check the [link](https://chunml.github.io/ChunML.github.io/project/Installing-NVIDIA-Docker-On-Ubuntu-16.04/)

How to install and use docker (detailed). [Link](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04?fbclid=IwAR2zWGd0M5CFoTdrKUkbCiEhLagv9YoqNHi_Wp8jBROsRNDAnJkZqEkP5Tk)

How to install specific version of some packager? [Link](https://askubuntu.com/questions/428772/how-to-install-specific-version-of-some-package?fbclid=IwAR0ghBWv8PZGhyvg4IcFvsq_ImtpQ5nYNozd9M4I7Po1QXK03mbB6MuApYg)

Install docker on ubuntu 18.04 [link](https://phoenixnap.com/kb/how-to-install-docker-on-ubuntu-18-04?fbclid=IwAR0ghBWv8PZGhyvg4IcFvsq_ImtpQ5nYNozd9M4I7Po1QXK03mbB6MuApYg)

## Good suggestion for oom-killer

[link](https://stackoverflow.com/questions/9199731/understanding-the-linux-oom-killers-logs)

Memory management in Linux is a bit tricky to understand, and I can't say I fully understand it yet, but I'll try to share a little bit of my experience and knowledge.

Short answer to your question: Yes there are other stuff included than whats in the list.

What's being shown in your list is applications run in userspace. The kernel uses memory for itself and modules, on top of that it also has a lower limit of free memory that you can't go under. When you've reached that level it will try to free up resources, and when it can't do that anymore, you end up with an OOM problem.

From the last line of your list you can read that the kernel reports a total-vm usage of: 1498536kB (1,5GB), where the total-vm includes both your physical RAM and swap space. You stated you don't have any swap but the kernel seems to think otherwise since your swap space is reported to be full (Total swap = 524284kB, Free swap = 0kB) and it reports a total vmem size of 1,5GB.

Another thing that can complicate things further is memory fragmentation. You can hit the OOM killer when the kernel tries to allocate lets say 4096kB of continous memory, but there are no free ones availible.

Now that alone probably won't help you solve the actual problem. I don't know if it's normal for your program to require that amount of memory, but I would recommend to try a static code analyzer like cppcheck to check for memory leaks or file descriptor leaks. You could also try to run it through Valgrind to get a bit more information out about memory usage.

As I understand, the size of the virtual memory that a process uses is listed as "total-vm". Part of it is really mapped into the RAM itself (allocated and used). This is "RSS".

Part of the RSS is allocated in real memory blocks (other than mapped into a file or device). This is anonymous memory ("anon-rss") and there is also RSS memory blocks that are mapped into devices and files ("file-rss").

So, if you open a huge file in vim, the file-rss would be high, on the other side, if you malloc() a lot of memory and really use it, your anon-rss would be high also.

On the other side, if you allocate a lot of space (with malloc()), but nevers use it, the total-vm would be higher, but no real memory would be used (due to the memory overcommit), so, the rss values would be low.
