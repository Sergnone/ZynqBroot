import vitis

# 1. Create a Vitis client instance
client = vitis.create_client()

# 2. Set the Vitis workspace path
workspace_location = "workspace"
client.set_workspace(path=workspace_location)

# 3. Define platform parameters
platform_name = 'platform'
hw_design_xsa = '../XSA/top_design_wrapper-smp.xsa'
# Example for a standalone (bare-metal) OS
# os_type = "standalone"
# cpu_type = "psu_cortexa53_0" 
# Example for Linux OS
os_type = "linux"
cpu_type = "ps7_cortexa9_0" # or another appropriate processor

# 4. Create the Platform Component
platform_comp = client.create_platform_component(
    name=platform_name,
    hw_design=hw_design_xsa,
    os=os_type,
    cpu=cpu_type,
    domain_name=f"{os_type}_{cpu_type}" # Optional: specify a domain name
)

# 5. Optional: Add software repositories or components (e.g., for Linux)
# client.set_sw_repo(level="local", path="<path_to_sw_repo>")
# If you have specific software components (like a system device tree user file), you can add them here.

# 6. Build the platform component
platform_comp.build()

print(f"Platform component '{platform_name}' built successfully.")
# The output .xpfm file will be located at: workspace_location/platform_name/export/platform_name/platform_name.xpfm

# 7. Close the client connection
client.close()
