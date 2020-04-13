# Rootkit Kernel Programming

##### Implemented a portion of Rootkit functionality 
##### The detailed descripition of the project is inside requirements.pdf


## Usage

Tests were ran on Duke virtual machine with **Ubuntu 16**.


```
make # build sneaky_mod and sneaky_process

sudo ./sneaky_process #run
```

The `sneaky_process` quits with `q`. 

You should have two terminals open at the same time. For one is running sneaky_process, it accounts for insertion of `sneaky_mod`. For another is a normal terminal, you should be able to run the command in `requirement.pdf` with the sneaky results.

## Tips

### Output

For the output of `printk`, it should be shown in `/var/log/syslog`.

You can use this command to show the last 30 lines: `sudo tail -n 30 /var/log/syslog`

