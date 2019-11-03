#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
struct array_3d
{
  using size_type = typename std::vector<T>::size_type;
  using difference_type = typename std::vector<T>::difference_type;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  // default constructs the whole 3d_array
  array_3d(const std::size_t x_size, const std::size_t y_size, const std::size_t z_size) : m_x(x_size), m_y(y_size), m_z(z_size), m_values(m_x * m_y * m_z) {}
  array_3d(const std::size_t x, const std::size_t y, const std::size_t z, std::vector<T>&& src) : m_x(x), m_y(y), m_z(z), m_values(std::move(src))
  {
    // assert(m_values.size() == m_x * m_y * m_z);
  }

  ~array_3d() = default; // this defaults all copy/move constructors and assignment operators

  iterator begin() { return m_values.begin(); }
  iterator begin() const { return m_values.begin(); }
  const_iterator cbegin() const { return m_values.cbegin(); }
  iterator end() { return m_values.end(); }
  iterator end() const { return m_values.end(); }
  const_iterator cend() const { return m_values.cend(); }

  T& at(const std::size_t x, const std::size_t y, const std::size_t z) { return m_values[x * m_y * m_z + y * m_z + z]; }
  T const& at(const std::size_t x, const std::size_t y, const std::size_t z) const { return m_values[x * m_y * m_z + y * m_z + z]; }

  std::size_t x() const noexcept { return m_x; }
  std::size_t y() const noexcept { return m_y; }
  std::size_t z() const noexcept { return m_z; }

private:
  std::size_t m_x;
  std::size_t m_y;
  std::size_t m_z;
  std::vector<T> m_values;
};

array_3d<unsigned> build_prefix_xor(array_3d<unsigned> const& values)
{
  array_3d<unsigned> prefix(values.x(), values.y(), values.z());
  for (std::size_t i = 0; i < values.x(); ++i)
  {
    for (std::size_t j = 0; j < values.y(); ++j)
    {
      for (std::size_t k = 0; k < values.z(); ++k)
      {
        if (k == 0)
        {
          prefix.at(i, j, k) = values.at(i, j, k);
        }
        else
        {
          prefix.at(i, j, k) = prefix.at(i, j, k - 1) ^ values.at(i, j, k);
        }
      }
    }
  }
  for (std::size_t i = 0; i < values.x(); ++i)
  {
    for (std::size_t j = 1; j < values.y(); ++j)
    {
      for (std::size_t k = 0; k < values.z(); ++k)
      {
        prefix.at(i, j, k) ^= prefix.at(i, j - 1, k);
      }
    }
  }

  for (std::size_t i = 1; i < values.x(); ++i)
  {
    for (std::size_t j = 0; j < values.y(); ++j)
    {
      for (std::size_t k = 0; k < values.z(); ++k)
      {
        prefix.at(i, j, k) ^= prefix.at(i - 1, j, k);
      }
    }
  }
  return prefix;
}


unsigned xor_query(array_3d<unsigned> const& prefix, const std::size_t x1, const std::size_t y1, const std::size_t z1, const std::size_t x2, const std::size_t y2, const std::size_t z2)
{
  unsigned xor_1 = 0, xor_2 = 0, xor_3 = 0, xor_4 = 0, xor_5 = 0, xor_6 = 0, xor_7 = 0;
  if (z1)
  {
    xor_1 = prefix.at(x2, y2, z1 - 1);
  }
  if (y1)
  {
    xor_2 = prefix.at(x2, y1 - 1, z2);
  }
  if (y1 && z1)
  {
    xor_3 = prefix.at(x2, y1 - 1, z1 - 1);
  }
  if (x1)
  {
    xor_4 = prefix.at(x1 - 1, y2, z2);
  }
  if (x1 && z1)
  {
    xor_5 = prefix.at(x1 - 1, y2, z1 - 1);
  }
  if (x1 && y1)
  {
    xor_6 = prefix.at(x1 - 1, y1 - 1, z2);
  }
  if (x1 && y1 && z1)
  {
    xor_7 = prefix.at(x1 - 1, y1 - 1, z1 - 1);
  }
  return prefix.at(x2, y2, z2) ^ xor_1 ^ xor_2 ^ xor_3 ^ xor_4 ^ xor_5 ^ xor_6 ^ xor_7;
}

int main()
{
  unsigned a, b, c;
  std::cin >> a >> b >> c;
  std::vector<unsigned> values; values.reserve(a * b * c);
  const unsigned num_input_rows = a * b;
  for (unsigned i = 0; i < num_input_rows; ++i)
  {
    std::copy_n(std::istream_iterator<unsigned>(std::cin), c, std::back_inserter(values));
  }
  const array_3d<unsigned> tensor_values(a, b, c, std::move(values));

  const array_3d<unsigned> prefix = build_prefix_xor(tensor_values);

  unsigned q;
  std::cin >> q;
  for (std::size_t i = 0; i < q; ++i)
  {
    unsigned x1, y1, z1, x2, y2, z2;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    std::cout << xor_query(prefix, x1 - 1, y1 - 1, z1 - 1, x2 - 1, y2 - 1, z2 - 1) << std::endl;
  }

  return 0;
}