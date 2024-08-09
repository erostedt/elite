#pragma once

#include <exception>
#include <ranges>
#include <sstream>
#include <vector>

#define NOT_IMPLEMENTED (throw Assert::NotImplemented(__FUNCTION__))

namespace Assert
{

class ShapeMismatch : public std::exception
{

  public:
    ShapeMismatch(const size_t lhs, const size_t rhs)
    {
        std::stringstream message;
        message << "ShapeMismatch [" << lhs << "]" << " vs " << "[" << rhs << "]";
        m_message = message.str();
    }

    virtual const char *what() const noexcept override
    {
        return m_message.c_str();
    }

  private:
    std::string m_message{};
};

class ElementMismatch : public std::exception
{

  public:
    template <typename T> ElementMismatch(const T lhs, const T rhs, const size_t position)
    {
        std::stringstream message;
        message << "ElementMismatch [" << lhs << "]" << " vs " << "[" << rhs << "] at position: " << position;
        m_message = message.str();
    }

    template <typename T> ElementMismatch(const T lhs, const T rhs)
    {
        std::stringstream message;
        message << "ElementMismatch [" << lhs << "]" << " vs " << "[" << rhs << "]";
        m_message = message.str();
    }

    virtual const char *what() const noexcept override
    {
        return m_message.c_str();
    }

  private:
    std::string m_message{};
};

class NotOneOfError : public std::exception
{

  public:
    template <typename T> NotOneOfError(const T &lhs, const std::vector<T> &options)
    {
        std::stringstream message;
        message << "Element [" << lhs << "] is not found in: [";
        for (const T &option : options)
        {
            message << option << ", ";
        }
        message << "]";

        m_message = message.str();
    }

    virtual const char *what() const noexcept override
    {
        return m_message.c_str();
    }

  private:
    std::string m_message{};
};

class NotImplemented : public std::exception
{

  public:
    NotImplemented(const char *function)
    {
        std::ostringstream message;
        message << function << " is not implemented";
        m_message = message.str();
    }

    virtual const char *what() const noexcept override
    {
        return m_message.c_str();
    }

  private:
    std::string m_message{};
};

template <typename Container> static void equals(const Container &lhs, const Container &rhs)
{
    if (std::size(lhs) != std::size(rhs))
    {
        throw ShapeMismatch(std::size(lhs), std::size(rhs));
    }

    const auto &[left, right] = std::ranges::mismatch(lhs, rhs);
    if (left != std::ranges::cend(lhs))
    {
        throw ElementMismatch(*left, *right, std::ranges::distance(lhs.cbegin(), left));
    }
}

template <typename T> static void equal(const T &lhs, const T &rhs)
{
    if (lhs != rhs)
    {
        throw ElementMismatch(lhs, rhs);
    }
}

template <typename T> static void equal_one_of(const T &lhs, const std::vector<T> &options)
{
    for (const T &option : options)
    {
        if (lhs == option)
        {
            return;
        }
    }
    throw NotOneOfError(lhs, options);
}

}; // namespace Assert
