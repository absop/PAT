import os
import shutil


def clean(dir):
    for file in os.listdir(dir):
        path = os.path.join(dir, file)

        if file.endswith(".exe"):
            print("rm -f", path)
            os.remove(path)

        elif os.path.isdir(path):
            clean(path)

def merge(dir):
    advanced = os.path.join("Advanced")
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


if __name__ == "__main__":
    merge(os.path.dirname(__file__))
    clean(os.path.dirname(__file__))
