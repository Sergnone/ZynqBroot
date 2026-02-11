# 2026-02-11T20:10:44.813712120
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace")

platform = client.create_platform_component(name = "platform",hw_design = "$COMPONENT_LOCATION/../../../XSA/top_design_wrapper_02.xsa",os = "linux",cpu = "ps7_cortexa9_0",domain_name = "linux_ps7_cortexa9_0")

platform = client.get_component(name="platform")
status = platform.build()

