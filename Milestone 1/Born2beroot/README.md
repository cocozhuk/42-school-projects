*This project has been created as part of the 42 curriculum by kzhu.*

# Born2beroot

## Description

The goal was to build a Virtual Machine (VM) from scratch without using any graphical interfaces (GUI).
I set up a secure server using Debian 12, configure encrypted partitions, and enforce strict security policies for passwords and network access.
Basically, it's about building an operating system that is locked down and secure, acting as a solid foundation ("root") for services.

## Instructions

This is an operating system administrative project, there is no make or compilation.
The only thing to get it started is simply setting up the Virtual Machine in VirtualBox.

1. Signature Verification

Before starting, you must verify that the virtual disk has not been altered since submission.
*Reference: open <signature.txt> at the root of the git cloned folder to see the original hash.
*Command: run this command line in the sgoinfre folder containing the <kzhu.vdi> file: shasum kzhu.vdi
*Result: the printed number must match the one in `signature.txt` exactly.

2. Execution

*Open VirtualBox.
*If the machine is not listed, click Add (Machine > Add) and select the kzhu.vbox file.
*Click Start.
*You will be prompted for the LUKS password to unlock the hard drive.
*Once booted, log in with user kzhu or root.

3. SSH Connection

The VM is configured to listen on port 4242 internally (as per the subject), but I have set up Port Forwarding to port 8888 on the host to avoid local conflicts.
To connect to the machine, open a terminal on your computer and run: bash ssh kzhu@localhost -p 8888

##Resources & AI Usage

References

*Born2BeRoot Guide（for the general guiding through out the project） https://noreply.gitbook.io/born2beroot
*Virtual Machines explained in 15 Mins (to kick off and understand the meaning of a virtual machine)  https://www.youtube.com/watch?v=mQP0wqNT_DI&list=PLvrGkX6pcHIC8-UKfChyYGcQtvJtniH3c
*How SSH Works (to have better understanding of how SSH works) https://www.youtube.com/watch?v=Dm4_k25PEow&list=PLvrGkX6pcHIC8-UKfChyYGcQtvJtniH3c&index=4

AI Usage

I used AI assistance (Gemini) during this project for the following specific tasks:
*Troubleshooting Network: I had issues with "Connection Closed" errors on SSH. AI helped me debug VirtualBox port forwarding and suggested switching the host port to 8888 to fix a zombie port issue on Windows.
*Concept Explanations: Used to get "human" explanations of complex topics like the difference between Aptitude and Apt, and AppArmor vs SELinux for the defense preparation.


##Project Description & Design Choices

Operating System Choice

*Why Debian?
It is known for being stable and reliable. It uses the apt package manager, which has a huge community and lots of documentation, making it great for learning.
*Why not Rocky?
Rocky Linux is an enterprise system, which are powerful but much more complex to configure for a first project. Debian was the logical choice.

Design Choices

*Partitioning: I used LVM (Logical Volume Management) inside an encrypted partition as suggested. This lets me resize partitions later if needed, while keeping the data secure (LUKS encryption).
*User Management: I avoided using the Root account for daily tasks to prevent accidental system damage. Instead, I created a standard user (kzhu) and assigned them to the sudo group for administrative privileges and the user42 group as required by the subject.
*Security: I configured a strict password policy (expiry every 30 days, complex passwords) and set up sudo to require a password.
*Services: the server is minimal. It only runs SSH (for remote connection) and UFW (firewall) to block all ports except 4242.

Comparisons

Debian vs Rocky Linux
        Debian: uses .deb files and apt. It is community-driven and focuses on stability.
        Rocky: uses .rpm files and dnf. It is a clone of RHEL (Red Hat) and is focused on corporate servers.
AppArmor vs SELinux
        AppArmor (Debian): secures programs by file path. use specific file path to block the access to other file path.
        SELinux (Rocky): secures programs by labels. Every file has a tag. It is very strict and harder to troubleshoot.
UFW vs Firewalld
        UFW (Uncomplicated Firewall): a simple tool to manage the firewall. It is perfect for single servers.
        Firewalld: a more dynamic tool that uses "Zones" (like Home, Work, Public). It is a bit too much for this project.
VirtualBox vs UTM
        VirtualBox: The standard free virtualization tool. It works great on Windows and Intel systems.
        UTM: A tool mainly used on newer Macs (Apple Silicon M1/M2/M3) to emulate different computer architectures. Since I am using a standard PC, VirtualBox was the best choice.
