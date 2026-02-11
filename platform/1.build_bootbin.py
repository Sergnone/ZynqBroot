import os
import subprocess
import sys

def generate_boot_bin(bif_file, output_bin, architecture):
    """
    Generates a BOOT.bin file from a BIF file using the bootgen utility.

    Args:
        bif_file (str): Path to the input .bif file.
        output_bin (str): Path for the output .bin file (e.g., 'BOOT.bin').
        architecture (str): Target device architecture (e.g., 'zynq', 'zynqmp', 'versal').
    """
    # Ensure the bootgen tool is in your system's PATH
    # or provide the full path to the bootgen executable.
    command = f"bootgen -image {bif_file} -o {output_bin} -arch {architecture} -w on"
    
    print(f"Running command: {command}")

    try:
        # Execute the command
        subprocess.run(command, shell=True, check=True, stdout=sys.stdout, stderr=sys.stderr)
        print(f"Successfully generated {output_bin}")
    except subprocess.CalledProcessError as e:
        print(f"Error during bootgen execution: {e}")
        sys.exit(1)
    except FileNotFoundError:
        print("Error: 'bootgen' command not found.")
        print("Please ensure the AMD/Xilinx tools environment (Vitis/PetaLinux) is sourced correctly.")
        sys.exit(1)

if __name__ == "__main__":
    # --- Example Usage ---
    # Replace with your actual file names and architecture
    BIF_FILE = "bifimage/bootgen.bif"
    OUTPUT_FILE = "BOOT.bin"
    DEVICE_ARCH = "zynq" # or 'zynq', 'zynqmp', 'versal', etc.

    if os.path.exists(BIF_FILE):
        generate_boot_bin(BIF_FILE, OUTPUT_FILE, DEVICE_ARCH)
    else:
        print(f"Error: BIF file '{BIF_FILE}' not found.")
        sys.exit(1)
