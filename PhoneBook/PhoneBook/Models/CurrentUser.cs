using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Security.Principal;

namespace PhoneBook.Models
{
    public class CurrentUser
    {
        public static IIdentity user_id;
    }
}