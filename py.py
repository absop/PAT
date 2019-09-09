import os
import html
import shutil


template = """
# PAT

My PAT solutions.

Welcome to contribute code and star.

## Summary

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


def maketable(dir):
    advanced = os.path.join("AdvancedLevel_C")
    linkfmt = "[`%s`][%s]"
    language = {
        "md": "Markdown", "c": "C",
        "c++": "Cpp", "cpp": "Cpp",
        "py": "Python"
    }
    exercises, source, footnotes = {}, [], []
    for file in sorted(os.listdir(advanced)):
        idnum = file[:4]
        if idnum.isdigit() and file.endswith(".md"):
            ident = "README" + idnum
            readme = linkfmt % (file[5:-10], ident)
            link = file.replace(" ", "%20")
            footnotes.append("[%s]: AdvancedLevel_C/%s" % (ident, link))
            exercises[idnum] = [readme, file[-8:-6], []]

        else:
            ext = os.path.splitext(file)[1].lstrip(".").lower()
            if ext in language:
                source.append(file)

    for file in source:
        idnum = file[:4]
        if idnum in exercises:
            exercises[idnum][2].append(linkfmt % (file, file))
            footnotes.append("[%s]: AdvancedLevel_C/%s" % (file, file))

    for idnum in exercises:
        exercises[idnum][2] = ",".join(exercises[idnum][2])
    footnotes = "\n".join(footnotes)

    len2 = max([len(v[0]) for v in exercises.values()])
    rowfmt = "|%s|%-" + str(len2) + "s|%s|%s|\n"
    table = rowfmt % ("标号", "标题", "分数", "代码")
    table += rowfmt % ("---", len2 * "-", "---", "---")
    for idnum in exercises:
        title, score, src = exercises[idnum]
        table += rowfmt % (idnum, title, score, src)

    return (table, footnotes)


def makereadme(dir):
    toc, footnotes = maketable(dir)
    text = template.format(toc=toc)
    text += "\n\n" + footnotes
    with open("README.md", "w+", encoding="utf-8") as readme:
        readme.write(text)


if __name__ == "__main__":
    makereadme(os.path.dirname(__file__))
    # isolate(os.path.dirname(__file__))
    # merge(os.path.dirname(__file__))
    # clean(os.path.dirname(__file__))
