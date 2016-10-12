%define real_name openkeeper
%define debug_package %{nil}

Name: openkeeper-cli
Version: 2.0
Release: 1
License: GNU GPL v2
Summary: Netkeeper for Linux
Group: Applications/System
URL: https://github.com/Eventide/openkeeper-cli
Packager: Stawidy <duyizhaozj321@yahoo.com>
Requires: rp-pppoe openssl
BuildRequires: gcc libopenssl-devel
Source0: %{name}-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-build

%description
Netkeeper for Linux.

%prep
%setup -q

%build
cd dialnetkeeper
make

%install
mkdir -p %{buildroot}%{_bindir}/
mkdir -p %{buildroot}%{_sbindir}/
mkdir -p %{buildroot}%{_datadir}/%{real_name}/
install -m755 dialnetkeeper/dialnetkeeper %{buildroot}%{_bindir}/
install -m755 ok %{buildroot}%{_sbindir}/
install -m755 ok-config %{buildroot}%{_sbindir}/
install -m755 ok-stop %{buildroot}%{_sbindir}/
install -m755 ok-start %{buildroot}%{_sbindir}/
install -m755 ok-connect %{buildroot}%{_sbindir}/
install -m644 pppoe.conf %{buildroot}%{_datadir}/%{real_name}/
install -m644 pap-secrets %{buildroot}%{_datadir}/%{real_name}/

%clean
rm -rf %{buildroot}

%pre

%post

%preun

%postun

#%trigger

#%triggerin

#%triggerun

%files
%dir %{_datadir}/%{real_name}/
%attr(0755, root, root) "%{_bindir}/dialnetkeeper"
%attr(0755, root, root) "%{_sbindir}/ok"
%attr(0755, root, root) "%{_sbindir}/ok-config"
%attr(0755, root, root) "%{_sbindir}/ok-connect"
%attr(0755, root, root) "%{_sbindir}/ok-start"
%attr(0755, root, root) "%{_sbindir}/ok-stop"
%attr(0644, root, root) "%{_datadir}/%{real_name}/pap-secrets"
%attr(0644, root, root) "%{_datadir}/%{real_name}/pppoe.conf"

%changelog
* Mon Oct 10 2016 Stawidy <duyizhaozj321@yahoo.com>
- Initial version.
