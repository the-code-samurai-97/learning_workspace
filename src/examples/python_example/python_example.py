
import importlib.metadata as metadata

def get_installed_modules():
    installed_modules = {}
    for dist in metadata.distributions():
        installed_modules[dist.metadata["Name"]] = dist.version

    return installed_modules

def print_module_versions():
    installed_modules = get_installed_modules()
    sorted_dict_installed_modules = dict(sorted(installed_modules.items()))
    # Print the module names and their versions
    for module, version_info in sorted_dict_installed_modules.items():
        print(f"{module}: {version_info}")

if __name__ == "__main__":
    print("List of installed pip module versions:")
    print_module_versions()
    