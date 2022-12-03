include(FetchContent)

# googletest
FetchContent_Declare(googletest
	URL      https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz
	URL_HASH SHA256=81964fe578e9bd7c94dfdb09c8e4d6e6759e19967e397dbea48d1c10e45d0df2
)
FetchContent_MakeAvailable(googletest)

