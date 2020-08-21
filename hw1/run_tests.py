import subprocess, json, os, re
from functools import reduce

PROBLEM = "hw1"
TOTAL_TEST = 15

PEN_PER_FAILURE = 5
EACH_STYLE_VIOLATION = 3
MAX_STYLE = 15
TOTAL_HW = PEN_PER_FAILURE * TOTAL_TEST

PASS_PHRASE = "PASSED"
FAIL_PHRASE = "FAILED"
STYLE_PHRASE = "STYLE"

def one_test(problem):

    def count(p, iterable):
        count = 0
        for item in iterable:
            if p(item):
                count += 1
        return count

    def parse_output(output):

        lines = output.splitlines()

        # failed_test = count(lambda line: "FAILED" in line, lines)
        passed_test = count(lambda line: PASS_PHRASE in line, lines)

        failed_test_penalty = PEN_PER_FAILURE * (TOTAL_TEST - passed_test)

        total_style_violations = count(lambda line: line.startswith(STYLE_PHRASE), lines)

        style_penalty = min(total_style_violations * EACH_STYLE_VIOLATION, MAX_STYLE)

        total_penalty = failed_test_penalty + style_penalty

        msg = "Style violation {} pt each ({} at most): {}\nFailed (non-passing) tests {} pt each: {}\n".format(
                                                    EACH_STYLE_VIOLATION,
                                                    MAX_STYLE,
                                                    total_style_violations,
                                                    PEN_PER_FAILURE,
                                                    TOTAL_TEST - passed_test)

        return (total_penalty, msg + "\n\n==Console Output==\n\n" + output)

    # Check existence of the source file

    if not os.path.exists(problem + '.c'):
        score = 0.0
        msg = "Expecting C source file: " + problem + ".c"
    else:
        command = ['make']
        try:
            output = subprocess.check_output(command, stderr=subprocess.STDOUT)
        except subprocess.CalledProcessError as e:
            output = e.output

        (points_off, msg) = parse_output(output.decode("utf-8"))
        score = TOTAL_HW - points_off

    return {
        "name" : problem,
        "score" : score,
        "max_score" : TOTAL_HW,
        "output" : msg
    }


def main():
    result = one_test(PROBLEM)
    json_output = { "visibility": "visible",
        "stdout_visibility": "visible",
        "tests": [result],
        "leaderboard": [{ "name": "Score", "value": result['max_score']}]
    }

    print(json.dumps(json_output))

if __name__ == '__main__':
    main()
