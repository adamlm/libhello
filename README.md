# The Hello Library

The Hello Library (`libhello`) serves as a "hello-world" CMake project.

## Organization

The `libhello` project comprises several directories:

```text
libhello
|- cmake/      CMake scripts
|- docs/       Project documentation sources
|- examples/   Programs demonstrating how to use libhello
|- include/    Header files (.hpp)
|- packaging/  Files related to packaging formats (.deb, .rpm, etc.)
|- src/        Source files (.cpp) 
|- test/       Unit tests
```

## Building and installing

You can integrate `libhello` into other CMake projects through the `add_subdirectory(...)` command, or you can build it
by itself as a standalone project.  You can use `FetchContent` or [CPM](https://github.com/cpm-cmake/CPM.cmake)
incorporate `libhello` into your project. There are several CMake customization options listed in the table below. You
can also find them in the `options.cmake` file.

### Dependencies

The library depends only on [{fmt}](https://fmt.dev/latest/index.html) (a modern formatting library), which gets
included as a source dependency through CPM. You can see `libhello`'s dependencies in the `dependencies.cmake` file.

### Build steps

For building the library with the default options, follow these steps:

1. Configure the CMake project

   ```shell
   $ cmake -B build .
   ```

2. Build the library

   ```shell
   $ cmake --build build
   ```

3. (Optional) Install the library

   ```shell
   $ sudo cmake --install build  # Install to /usr/local/
   ```
   or
   ```shell
   $ cmake --install build --prefix=<install_path>  # Install to custom location
   ```

### Packaging

The Hello Library uses CPack to generate different packaging formats. To build a Debian package (`.deb` file), for
example, follow these step:

1. Configure the CMake project

   ```shell
   $ cmake -B build . -DCMAKE_BUILD_TYPE=Release
   ```
   
2. Change directories (`cd`) into the project's binary directory (`build`)

   ```shell
   $ cd build
   ```

3. Execute CPack and specify the Debian package generator (the `-G "DEB"` flag)

   ```shell
   $ cpack -G "DEB"
   ```
   
The generated package file should be located at `libhello/build/libhello-0.1.0-Linux.deb`. You can now install
`libhello` through `apt` using

```shell
$ sudo apt install ./libhello-0.1.0-Linux.deb 
```

### Project CMake options

| Option                             | Default value             | Description                   |
|------------------------------------|---------------------------|-------------------------------|
| `libhello_BUILD_TESTS`             | `${PROJECT_IS_TOP_LEVEL}` | Build tests                   |
| `libhello_BUILD_DOCS`              | `${PROJECT_IS_TOP_LEVEL}` | Build documentation           |
| `libhello_BUILD_EXAMPLES`          | `${PROJECT_IS_TOP_LEVEL}` | Build example programs        |
| `libhello_BUILD_PACKAGING`         | `${PROJECT_IS_TOP_LEVEL}` | Build packaging artifacts     |
| `libhello_BUILD_INSTALL`           | `${PROJECT_IS_TOP_LEVEL}` | Build CMake install targets   |
| `libhello_EXPORT_COMPILE_COMMANDS` | `${PROJECT_IS_TOP_LEVEL}` | Generate compilation database |

## Support

Need some help or want to chat about the library? Head to the repository's
[Discussions tab](https://github.com/adamlm/libhello/discussions) to connect with someone.

## Contributing

Want to help improve the library? Check out the [contribution guidelines](CONTRIBUTING.md) to get started.

## License

See the [`LICENSE.md`](LICENSE.md) file for license information.
