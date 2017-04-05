#!/usr/bin/env python

import os
import sys
from argparse import ArgumentParser

def gen(yaml_file, output_dir):
    

if __name__ == '__main__':
    parser = ArgumentParser()
    # Groups of sensors and how they should be monitored yaml file
    parser.add_argument("-y", "--yaml", dest="input_yaml",
                        default=
                        "example/sensor_monitoring_defs.yaml",
                        help=
                        "Input sensor monitoring definition yaml file to parse")
    parser.add_argument("-o", "--outdir", dest="output_dir",
                        default=
                        ".",
                        help=
                        "Output directory for source files generated")
    args = parser.parse_args(sys.argv[1:])

    # Verify given yaml file exists
    yaml_file = os.path.abspath(args.input_yaml)
    if not os.path.isfile(yaml_file):
        print "Unable to find input yaml file " + yaml_file
        exit(1)

    gen(yaml_file, output_dir)
