#include <algorithm>
#include <memory>
#include <vector>

/* TODO:
 * Options
 * VALUE_OPT examples: --file-name="blablabla" or --file-name=blablabla
 * BOOL_OPT examples: --verbose
 */
enum OptionType { BOOL_OPT, VALUE_OPT };

class Option {
private:
  OptionType otype;
  std::string name;
  char alias;

public:
  Option(OptionType otype, std::string name, char alias)
      : otype{otype}, name{name}, alias{alias} {};
};

class Command {
private:
  std::string name;
  Option opt;
};

class ComGate {
private:
  // std::unique_ptr<Command> global_command;
  std::unique_ptr<Command> global_command;
  std::unique_ptr<Option> global_option;
  std::string app_name;
  std::string version;
  std::string desc;
  std::vector<Command> commands;

public:
  ComGate(std::string appname) : app_name{appname} {
    version = "0.1.0";
    desc = "";
  };
  ComGate(std::string appname, std::string version, std::string desc)
      : app_name{appname}, version{version}, desc{desc} {};
  ~ComGate() = default;
  // TODO: parse and execute lambda
  void run();
};

int main() {
  auto cg = std::make_unique<ComGate>("teguh", "0.1.0", "ganteng");
  return 0;
}
