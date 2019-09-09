import os
import shutil


template = """
# PAT

My PAT solutions.

Welcome to contribute code and star.

题目集

{toc}
"""


def clean(dir):
    for file in os.listdir(dir):
        path = os.path.join(dir, file)

        if file.endswith(".exe"):
            print("rm -f", path)
            os.remove(path)

        elif os.path.isdir(path):
            clean(path)

def isolate(dir):
    advanced = os.path.join("AdvancedLevel_C")
    for file in os.listdir(advanced):
        src0 = os.path.join(advanced, file)
        if os.path.isdir(src0):
            readme = os.path.join(src0, file + ".md")
            if not os.path.exists(readme):
                with open(readme, "w+") as f:
                    f.write("#")
            continue
        dir0 = os.path.join(advanced, file[:4])
        dest = os.path.join(dir0, file)
        os.makedirs(dir0, exist_ok=True)
        shutil.move(src0, dest)

def merge(dir):
    advanced = os.path.join("AdvancedLevel_C")
    for file in os.listdir(advanced):
        dir0 = os.path.join(advanced, file)
        if os.path.isdir(dir0):
            for f in os.listdir(dir0):
                src0 = os.path.join(dir0, f)
                dest = os.path.join(advanced, f)
                shutil.move(src0, dest)
            shutil.rmtree(dir0, True)
            print("%s removed"%dir0)


def mktoc(dir):
    advanced = os.path.join("AdvancedLevel_C")
    fmt = '[%s](AdvancedLevel_C/%s)\n'
    toc = [f for f in os.listdir(advanced) if f.endswith(".md")]
    toc = [fmt % (f.rstrip(".md"), f) for f in sorted(toc)]
    toc = "\n".join(toc)

    return toc

def mkreadme(dir):
    toc = mktoc(dir)
    text = template.format(toc=toc)
    with open("README.md", "w+", encoding="utf-8") as readme:
        readme.write(text)


if __name__ == "__main__":
    mkreadme(os.path.dirname(__file__))
    # isolate(os.path.dirname(__file__))
    # merge(os.path.dirname(__file__))
    # clean(os.path.dirname(__file__))
