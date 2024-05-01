#!/bin/bash

ifconfig | grep -o 'ether [^ ]*' | awk '{print $2}'

