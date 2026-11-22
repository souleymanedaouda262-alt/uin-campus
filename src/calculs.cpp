#include "uincampus/calculs.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
namespace uin
{
double somme(std::span<const double> valeurs)
{
    return std::accumulate(valeurs.begin(), valeurs.end(), 0.0);
}
double moyenne(std::span<const double> notes)
{
    assert(!notes.empty() && "moyenne() : aucune note");
    return somme(notes) / static_cast<double>(notes.size());
}
double moyenne(std::span<const double> notes, std::span<const double> coefficients)
{
    assert(!notes.empty() && notes.size() == coefficients.size());
    double total{0.0};
    for (std::size_t i{0}; i < notes.size(); ++i) {
        total += notes[i] * coefficients[i];
    }
    const double poids = somme(coefficients);
    assert(poids > 0.0 && "moyenne() : somme des coefficients nulle");
    return total / poids;
}
Statistiques calculerStatistiques(std::span<const double> notes)
{
    assert(!notes.empty() && "calculerStatistiques() : aucune note");
    const auto [mini, maxi] = std::minmax_element(notes.begin(), notes.end());
    const double m = moyenne(notes);
    double ecarts{0.0};
    for (double n : notes) {
        ecarts += (n - m) * (n - m);
    }
    const double taille = static_cast<double>(notes.size());
    return Statistiques{*mini, *maxi, m, std::sqrt(ecarts / taille)};
}
int compterValidees(std::span<const double> notes, double seuil)
{
    return static_cast<int>(
        std::count_if(notes.begin(), notes.end(), [seuil](double n) { return n >= seuil; }));
}
double arrondir(double valeur, int decimales)
{
    const double facteur = std::pow(10.0, decimales);
    return std::round(valeur * facteur) / facteur;
}
} // namespace uin
