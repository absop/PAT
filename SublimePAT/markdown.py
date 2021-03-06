import sublime
import sublime_plugin


class FormatToMarkdownCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        view = self.view
        sample = "Sample (Input|Output)( \\d)?"
        specification = "(Input|Output) Specification"
        english = "((%s)|(%s)):" % (sample, specification)
        chinese = "((输入|输出)(格式|样例( \\d)?))："
        pattern = "^((%s)|(%s))$\n" % (chinese, english)
        secondary = view.find_all(pattern)
        end_char = sublime.Region(view.size() - 1, view.size())
        if view.substr(end_char) != "\n":
            view.insert(edit, view.size(), "\n")

        secondary.reverse()
        view.insert(edit, view.size(), "```\n")
        for r in secondary[:-3]:
            view.insert(edit, r.end(), "```\n")
            view.insert(edit, r.begin(), "```\n\n## ")

        view.insert(edit, secondary[-3].end(), "```\n")
        view.insert(edit, secondary[-3].begin(), "## ")
        view.insert(edit, secondary[-2].begin(), "## ")
        view.insert(edit, secondary[-1].begin(), "## ")
        view.insert(edit, view.line(0).end(), "\n")
        view.insert(edit, 0, "# ")
