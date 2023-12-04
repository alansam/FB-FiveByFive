#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <cstdlib>

// #define DEBUGZ_

using namespace std::literals::string_literals;

int main() {

  auto const pang = "A quick brown fox jumps over the lazy dog\n"s
                    "My girl wove six dozen plaid jackets before she quit\n"s
                    "Sixty zippers were quickly picked from the woven jute bag\n"s
                    "Sphinx of black quartz judge my vow\n"s
                    "A wizard's job is to vex chumps quickly in fog\n"s
                    "Brown jars prevented the mixture from freezing too quickly\n"s
                    "How vexingly quick daft zebras jump\n"s
                    "Jackdaws love my big sphinx of quartz\n"s
                    "We promptly judged antique ivory buckles for the next prize\n"s
                    "Glib jocks quiz nymph to vex dwarf\n"s
                    "When zombies arrive quickly fax Judge Pat\n"s
                    "Waxy and quivering jocks fumble the pizza\n"s
                    "Pack my box with five dozen liquor jugs\n"s
                    "The five boxing wizards jump quickly\n"s
                    "Farmer jack realized that big yellow quilts were expensive\n"s
                    ;

  std::istringstream ispang(pang);

#ifdef DEBUGZ_
std::copy(std::istream_iterator<std::string>(ispang),
            std::istream_iterator<std::string>(),
            std::ostream_iterator<std::string>(std::cout, "```"));
  std::cout << '\n' << std::endl;

  //  reset stream
  ispang.str(pang);
  ispang.clear();
#endif /* DEBUGZ_ */

  using qs = std::string;
  auto quints = std::vector<std::tuple<qs, qs, qs, qs, qs>>();
  auto iis = std::istream_iterator<std::string>(ispang);

  while (iis != std::istream_iterator<std::string>()) {
    auto vq = std::vector<qs>(5, ""s);
    auto ix = 0ul;
    do {
#ifdef DEBUGZ_
      std::cout << ix << ' ' << *iis++ << '\n';
#else
      vq[ix] = *iis++;
#endif /* DEBUGZ_ */
      ix++;
     if (ix >= 5) { break; }
    } while (iis != std::istream_iterator<std::string>());

#ifdef DEBUGZ_
    std::cout << vq[0] << ' '
              << vq[1] << ' '
              << vq[2] << ' '
              << vq[3] << ' '
              << vq[4]
              << std::endl;
#endif /* DEBUGZ_ */
    auto quint = std::make_tuple(vq[0], vq[1], vq[2], vq[3], vq[4]);
    quints.push_back(quint);
  }
  std::cout << quints.size() << std::endl;
  std::cout << '\n' << std::endl;

  auto row = 0ul;
  std::for_each(quints.cbegin(), quints.cend(), [&row](auto const & qt) {
    std::cout << std::setw( 5) << ++row << ": "
              << std::setw(11) << std::get<0>(qt)
              << std::setw(11) << std::get<1>(qt)
              << std::setw(11) << std::get<2>(qt)
              << std::setw(11) << std::get<3>(qt)
              << std::setw(11) << std::get<4>(qt)
              << '\n';
  });

    return EXIT_SUCCESS;
}
