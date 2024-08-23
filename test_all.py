import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import TypeVar


T = TypeVar("T")
LINE_SEPERATOR = "*" * 50


@dataclass(frozen=True)
class SectionResult:
    name: str
    passes: list[str]
    failes: list[str]

    @property
    def pass_count(self) -> int:
        return len(self.passes)

    @property
    def fail_count(self) -> int:
        return len(self.failes)

    @property
    def problem_count(self) -> int:
        return self.pass_count + self.fail_count


def passed(executable_path: Path) -> bool:
    try:
        subprocess.check_output([str(executable_path)])
    except subprocess.CalledProcessError:
        print(f"[{executable_path.name}] failed")
        return False

    print(f"[{executable_path.name}] passed")
    return True


def print_list_by_line(lst: list[T]) -> None:
    for element in lst:
        print(element)


def get_section_result(section: Path) -> SectionResult:
    passes = []
    failes = []
    for executable_path in section.iterdir():
        if passed(executable_path):
            passes.append(executable_path.name)
        else:
            failes.append(executable_path.name)

    passes.sort()
    failes.sort()
    return SectionResult(section.name, passes, failes)


def print_section_result(section_result: SectionResult) -> None:
    print(LINE_SEPERATOR)
    print(f"Section: {section_result.name}")
    print(f"Passes: {section_result.pass_count}/{section_result.problem_count}")
    print(LINE_SEPERATOR)
    print("Failes: ")
    print_list_by_line(section_result.failes)


def get_total_pass_count(section_results: list[SectionResult]) -> int:
    return sum(section_result.pass_count for section_result in section_results)


def get_total_problem_count(section_results: list[SectionResult]) -> int:
    return sum(section_result.problem_count for section_result in section_results)


def main():
    BUILD_DIR = Path("build")
    SECTIONS = ["array", "two_pointers", "sliding_window"]
    section_results = [get_section_result(BUILD_DIR / section) for section in SECTIONS]
    for section_result in section_results:
        print_section_result(section_result)

    total_pass_count = get_total_pass_count(section_results)
    total_problem_count = get_total_problem_count(section_results)
    print(LINE_SEPERATOR)
    print(f"Total passes: {total_pass_count}/{total_problem_count}")


if __name__ == "__main__":
    main()
