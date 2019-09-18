import os
import shutil


README_TEMPLATE = """
# 浙江大学 PAT 题解

`AdvancedLevel_C`目录下绝大部分题目使用`C语言`解答，少部分题目除C外还有`Python`或`C++`的解法，代码力求精简，格式规范统一，欢迎改进意见。

每道题都有相应的`Markdown`格式的题目描述，主要是为了方便在本地测试代码，与`Github`的Markdown格式或许有所出入，另外由于`Github`的`Markdown`不支持`LaTeX`数学公式，题目中的数学公式会显示异常。

[{level_goto_caption}]({level_goto_link})
## Summary
{level_this_caption}

{summary}

Welcome to contribute code and star.


{footnotes}
"""


def clean(dir):
    for file in os.listdir(dir):
        path = os.path.join(dir, file)

        if file.endswith(".exe"):
            print("rm -f", path)
            os.remove(path)

        elif os.path.isdir(path):
            clean(path)

def isolate(level):
    level_dir = os.path.join(level)
    for file in os.listdir(level_dir):
        src0 = os.path.join(level_dir, file)
        if os.path.isdir(src0):
            readme = os.path.join(src0, file + ".md")
            if not os.path.exists(readme):
                with open(readme, "w+") as f:
                    f.write("#")
            continue
        dir0 = os.path.join(level_dir, file[:4])
        dest = os.path.join(dir0, file)
        os.makedirs(dir0, exist_ok=True)
        shutil.move(src0, dest)

def merge(level):
    level_dir = os.path.join(level)
    for file in os.listdir(level_dir):
        dir0 = os.path.join(level_dir, file)
        if os.path.isdir(dir0):
            for f in os.listdir(dir0):
                src0 = os.path.join(dir0, f)
                dest = os.path.join(level_dir, f)
                shutil.move(src0, dest)
            shutil.rmtree(dir0, True)
            print("%s removed"%dir0)

def makesummary(level):
    level_dir = os.path.join(level)
    footnotefmt = "[%s]: "+ level + "/%s"
    linkfmt = "[`%s`][%s]"
    language = {
        "md": "Markdown", "c": "C",
        "c++": "Cpp", "cpp": "Cpp",
        "py": "Python"
    }
    exercises, source, footnotes = {}, [], []
    for file in sorted(os.listdir(level_dir)):
        idnum = file[:4]
        if idnum.isdigit() and file.endswith(".md"):
            ident = "README" + idnum
            readme = linkfmt % (file[5:-10], ident)
            link = file.replace(" ", "%20")
            footnotes.append(footnotefmt % (ident, link))
            exercises[idnum] = [readme, file[-8:-6], []]

        else:
            ext = os.path.splitext(file)[1].lstrip(".").lower()
            if ext in language:
                source.append(file)

    for file in source:
        idnum = file[:4]
        if idnum in exercises:
            exercises[idnum][2].append(linkfmt % (file, file))
            footnotes.append(footnotefmt % (file, file))

    for idnum in exercises:
        exercises[idnum][2] = ",".join(exercises[idnum][2])
    footnotes = "\n".join(footnotes)

    len2 = max([len(v[0]) for v in exercises.values()])
    rowfmt = "|%s|%-" + str(len2) + "s|%s|%s|\n"
    summary = rowfmt % ("标号", "标题", "分数", "代码")
    summary += rowfmt % ("---", len2 * "-", "---", "---")
    for idnum in exercises:
        title, score, src = exercises[idnum]
        summary += rowfmt % (idnum, title, score, src)

    return (summary, footnotes)


def makereadme(dir):
    # Advanced Level
    summary, footnotes = makesummary("AdvancedLevel_C")
    text = README_TEMPLATE.format(
        level_goto_caption="PAT (Basic Level) Practice （中文）",
        level_goto_link="BasicLevel.md",
        level_this_caption="PAT (Advanced Level) Practice",
        summary=summary,
        footnotes=footnotes)
    with open("README.md", "w+", encoding="utf-8") as file:
        file.write(text)
    # Basic Level
    summary, footnotes = makesummary("BasicLevel_C")
    text = README_TEMPLATE.format(
        level_goto_caption="PAT (Advanced Level) Practice",
        level_goto_link="README.md",
        level_this_caption="PAT (Basic Level) Practice （中文）",
        summary=summary,
        footnotes=footnotes)
    with open("BasicLevel.md", "w+", encoding="utf-8") as file:
        file.write(text)


if __name__ == "__main__":
    makereadme(os.path.dirname(__file__))
    # isolate(os.path.dirname(__file__))
    # merge(os.path.dirname(__file__))
    clean(os.path.dirname(__file__))
