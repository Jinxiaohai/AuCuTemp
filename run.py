#!/usr/bin/env python3


import subprocess


subprocess.call(("make",))
subprocess.call(("./main.exe", "./list/ampt.list", "./list/epsilon.list"))
