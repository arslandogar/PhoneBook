using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace PhoneBook.Controllers
{
    public class DashboardController : Controller
    {
        public ActionResult Index()
        {
            ViewBag.number_of_people = PersonController.ph.People.Count();
            List<Person> temp = new List<Person>();
            return View(temp);
        }        
    }
}