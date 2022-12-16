# dumpcerts

Dump certificates from one of the Windows certificate stores in PEM format:

- `CA` Certification authority certificates.
- `MY` A certificate store that holds certificates with associated private keys.
- `ROOT` Root certificates.
- `SPC` Software Publisher Certificate.

If no certificate store is specified, `ROOT` is used.
