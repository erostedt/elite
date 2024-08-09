import subprocess
from pathlib import Path


def passed(executable_path: Path) -> bool:
    try:
        subprocess.check_output([str(executable_path)])
    except subprocess.CalledProcessError:
        print(f"[{executable_path.name}] failed")
        return False

    print(f"[{executable_path.name}] passed")
    return True


def main():
    BUILD_DIR = Path("build")
    SECTIONS = ["array"]
    for section in SECTIONS:
        path = BUILD_DIR / section
        passes = [passed(executable_path) for executable_path in path.iterdir()]
        print(f"Passes: {sum(passes)}/{len(passes)}")


if __name__ == "__main__":
    main()
